#!/usr/bin/env python3

from sys import argv, exit
from os import path, chdir, makedirs, getcwd
from binascii import crc32
from subprocess import run, call, check_call, TimeoutExpired, CalledProcessError, DEVNULL
from datetime import datetime
from termcolor import colored, cprint
import toml

if len(argv) > 3:
    print('usage: ./allmaker toml-file [answer name]')
    exit(1)

config = toml.load(open(argv[1]))

# makerディレクトリの中で行われる
#
# 正解出力を作る
def casemake():
    def testmake(test):
        testname = test['Name']
        isText = ('Text' in test) and test['Text']

        print('# MakeTest {} {}cases'.format(testname, test['Number']))
        
        if not isText:
            # make testname
            print('# make {}'.format(testname))
            check_call(['make', testname], stdout=DEVNULL)
            st = 'yoyoyoyoyoy su papapapapapapa'
            hs = crc32((st+testname+config['hash']).encode())
        
        for i in range(test['Number']):
            # output filename
            ofn = '../in/' + testname + str(i) + '.in'

            if isText:
                # input filename
                ifn = '../examples/' + testname + str(i) + '.in'
                check_call(['cp', ifn, ofn])
            else:
                check_call(['./'+testname, str(i), str(hs)],
                    stdout=open(ofn, 'w'))
            # run verify
            check_call(['./'+config['verify']], stdin=open(ofn, 'r'), stdout=DEVNULL)

    # clear ./in
    print('# clear ./in')
    call(['rm', '-r', 'in'])
    makedirs('in', exist_ok=True)

    chdir('maker')
    # make verify
    print('# make verify')
    check_call(['make', config['verify']], stdout=DEVNULL)
    
    for test in config['tests']:
        testmake(test)

    # make clean
#    print('# make clean')
#    check_call(['make', 'clean'], stdout=DEVNULL)

    chdir('..')

# answerディレクトリの中で行われる
def solmake():
    print('# clear ./out')
    run(['rm', '-r', 'out'])
    makedirs('out', exist_ok=True)
    chdir('answer')

    # make answer
    ansname = config['answer']
    print('# make answer')
    run(['make', ansname], stdout=DEVNULL, check=True) 

    for test in config['tests']:
        testname = test['Name']
        for i in range(test['Number']):
            # ifn:input filename
            # ofn:output filename
            ifn = '../in/' + testname + str(i) + '.in'
            ofn = '../out/' + testname + str(i) + '.out'

            run(['./'+ansname],
                stdin=open(ifn, 'r'), stdout=open(ofn, 'w'), check=True)

    # make clean
#    print('# make clean')
#    run(['make', 'clean'], stdout=DEVNULL, check=True)

    chdir('..')


# answerディレクトリで行う。
# ジャッジする
def judgeother():
    def checkans(tl, answer):
        ansname = answer['Name']
        print('### Check {}'.format(ansname))
        makedirs('../other/'+ansname, exist_ok=True)
        check_call(['make', ansname], stdout=DEVNULL) # answerの実行ファイルを作成

        for test in config['tests']:
            testname = test['Name']
            for i in range(test['Number']):
                # ifn: input filename
                # afn: answer filename
                # ofn: output filename
                ifn = '../in/' + testname + str(i) + '.in'
                afn = '../out/' + testname + str(i) + '.out'
                ofn = '../other/' + ansname + '/' + testname + str(i) + '.out'

                # run
                res = ''
                start = datetime.now();

                try:
                    check_call(['./'+ansname],
                        stdin=open(ifn, 'r'), stdout=open(ofn, 'w'),
                        timeout=tl)
                except TimeoutExpired:
                    res = colored('TLE', on_color='on_blue')
                except CalledProcessError:
                    res = colored('RE', on_color='on_red')
                else:
                    end = datetime.now();
                    try:
                        # output check
                        # checkerが指定されていればそれを使い、なければdiffコマンドを使う
                        if 'checker' in config:
                            check_call(['../maker/'+config['checker'],
                                ifn, ofn, afn], stdout=DEVNULL)
                        else:
                            check_call(['diff', ofn, afn], stdout=DEVNULL)
                    except CalledProcessError:
                        res = colored('WA', on_color='on_yellow')
                    else:
                        res = colored('AC', on_color='on_green')

                end = datetime.now();

                usetime = end-start
                usemsec = usetime.seconds*1000 + usetime.microseconds // 1000
                print('res={:>3s}{:6d} msecs({} id={})'.format(res, usemsec, testname, i))

    tl = config['timeLimit']

    if 'checker' in config:
        # make checker
        chdir('maker')
        check_call(['make', config['checker']], stdout=DEVNULL)
        chdir('../')
    
    # answer
    chdir('answer')
    if len(argv) <= 2:
        # all check
        call(['rm', '-r', '../other'])
        makedirs('../other', exist_ok=True)
        for answer in config['answers']:
            checkans(tl, answer)
    else:
        # sigle check timelimit *= 3
        ansname = argv[2]
        for answer in config['answers']:
            if answer['Name'] == ansname:
                call(['rm', '-r', '../other/'+ansname])
                makedirs('../other/'+ansname, exist_ok=True)
                checkans(tl*3, answer);
#    check_call(['make', 'clean'], stdout=DEVNULL) # 最後にclean

print(colored('Start Casemake', on_color='on_magenta'))
casemake()
print(colored('Start Solmake', on_color='on_magenta'))
solmake()
print(colored('Start Judgeother', on_color='on_magenta'))
judgeother()

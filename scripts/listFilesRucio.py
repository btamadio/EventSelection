#!/usr/bin/env python
import sys,os
from subprocess import Popen,PIPE
dsList = sys.argv[1]
with open(dsList) as f:
    for line in f:
        p = Popen(['rucio','list-file-replicas',line.rstrip()],stdout=PIPE)
        output=p.stdout.read()
        for o in output.split('|'):
            if o.find('/projecta') != -1:
                print o[o.find('/projecta'):].rstrip()
            #else:
            #    print 'dataset not found',line.rstrip()

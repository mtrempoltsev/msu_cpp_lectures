import subprocess

def run(command):
    process = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    out = process.stdout.readlines()
    code = process.wait()
    return code, out

def isPing(line):
    line = line.rstrip()
    if line == "ping":
        return True
    if line == "pong":
        return False
    print("not ping not pong")
    quit()

code, out = run("test")
if code != 0:
    print("return value != 0")
    quit()

n = 1
for line in out:
    str = line.decode("utf-8").rstrip()
    if n == 1:
        last = isPing(str)
    else:
        current = isPing(str)
        if last == current:
            print("failed")
            quit()
        last = current
    n += 1

if n < 500000:
    print(n, "< 500000")
    quit()

print("ok")
import subprocess

def hash(string, gather=None, file_id=None):
    if file_id is None:
        f = open("./tmp.in", 'w+')
    else:
        f = open(f"./tmp/tmp-{file_id}.in", 'w+')
    f.write(string)
    f.close()

    if file_id is None:
        out = subprocess.check_output(['./main', './tmp.in']).decode('utf-8')
    else:
        out = subprocess.check_output(['./main', f'./tmp/tmp-{file_id}.in']).decode('utf-8')

    if gather is not None:
        g = open(f"./{gather}.txt", 'a+')
        g.write(out + '\n')
        g.close()
    return out

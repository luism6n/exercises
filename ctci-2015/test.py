import sys
import subprocess

question = sys.argv[1]

input_file = f"{question}.input.txt"
source_file = f"{question}.c"
executable = f"{question}.out"

try:
    subprocess.check_output(["gcc", "-o", executable, source_file])
except subprocess.CalledProcessError as e:
    print(e)
    sys.exit(1)


def cases(input_file):
    cases = []
    with open(input_file) as f:
        while True:
            inp = ""
            out = ""
            line = f.readline()
            if line.strip() != ">>":
                break

            line = f.readline()
            while line.strip() != "<<":
                inp += line
                line = f.readline()

            line = f.readline()
            while line.strip() != "":
                out += line
                line = f.readline()

            cases.append((inp, out))

    return cases


for inp, expected_out in cases(input_file):
    actual_out = subprocess.check_output(
        ["valgrind", "-q", "./" + executable],
        # ["./" + executable],
        text=True,
        input=inp,
    )
    try:
        print("success")
        assert actual_out == expected_out, (inp, actual_out, expected_out)
    except AssertionError as e:
        print("failure")
        print(e)

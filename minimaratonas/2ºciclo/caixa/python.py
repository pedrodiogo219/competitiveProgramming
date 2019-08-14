import random
import subprocess

class TestCreator:

  def __init__(self, testCase):
    self.testCase = testCase
    self.input = self.generateInput()
    self.output = self.generateOutput()
    self.createFiles()
    
  def createFile(self, filename, s):
    with open(filename, 'wb') as file:
      file.write(s)
      
  def createFiles(self):
    filename = 'file' + str(self.testCase)
    self.createFile('in/' + filename + '.in', self.input)
    self.createFile('sol/' + filename + '.out', self.output)
    
  def generateInput(self):
    limit = 1000000000000000000
    n = random.randint(1, 112)
    v = [random.randint(1, 1123)]
    for i in range(n):
      v.append(v[0] * random.randint(1, limit // v[0]))
    m = v[-1]
    ans = str(n) + ' ' + str(m) + '\n'
    ans += ' '.join(str(v[i]) for i in range(n))
    return ans.encode('utf-8')
    
  def generateOutput(self):
    solution = subprocess.run(
      args = [
        'python3',
        'solution.py'
      ],
      input = self.input,
      stdout = subprocess.PIPE,
      stderr = subprocess.STDOUT,
    )
    return solution.stdout

def main():
  for testCaseNumber in range(112):
    TestCreator(testCaseNumber)

main()
for f in $(find . -name "*problem[^.]*");
do
  echo $f/limits/c
  printf "echo 1\necho 1\necho 512\necho 2000\n" > $f/limits/c
  printf "echo 1\necho 1\necho 512\necho 2000\n" > $f/limits/cc
  printf "echo 5\necho 5\necho 512\necho 2000\n" > $f/limits/java
  printf "echo 5\necho 5\necho 512\necho 2000\n" > $f/limits/py2
  printf "echo 5\necho 5\necho 512\necho 2000\n" > $f/limits/py3
  (cd $f && zip -r "../problem.zip" . && cd ../..)
done

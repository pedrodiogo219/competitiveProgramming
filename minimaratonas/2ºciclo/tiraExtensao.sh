# for f in sol/*;
# do
#   #basename $f;
#   aux="${f%.in}";
#   novo="${aux%.out}";
#   mv "$f" "$novo";
# done;
#
# for f in in/*;
# do
#   #basename $f;
#   aux="${f%.in}";
#   novo="${aux%.out}";
#   mv "$f" "$novo";
# done

for f in $(find . -name *file[0-9]*) ;
do
  aux="${f%.in}";
  novo="${aux%.out}";
  mv "$f" "$novo" ;
done

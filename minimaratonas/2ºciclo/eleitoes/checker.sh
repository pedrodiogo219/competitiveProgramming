for f in sol/*;
do
  echo "$f"
  diff "sol/${f:4}" "candsol/${f:4}"
done

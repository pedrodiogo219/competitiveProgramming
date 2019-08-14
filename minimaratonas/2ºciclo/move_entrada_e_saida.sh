echo $1

rm -f "$1/output/*"
rm -f "$1/input/*"

echo "deve ter apagado"
cp $1/../sol/* "$1/output/"
cp $1/../in/* "$1/input/"

rm -rf "$1.zip"
(cd $1 && zip -r ../problem.zip . && cd ..)

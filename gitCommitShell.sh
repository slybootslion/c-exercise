echo "begin"
git pull
git add .
time=$(date "+%Y-%m-%d %H:%M:%S")
git commit -m "${time}"
git push
git push origin-github master
echo "end"

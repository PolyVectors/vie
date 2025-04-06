divider="-------------------------------------"
declare -a args=("tests/test.asm" "-h" "--help")

for arg in "${args[@]}"
do
	echo $divider
	echo "running vie ${arg}"
	echo ""
	
	./vie "$arg"
done

echo $divider
echo "running vie arg1 arg2 arg3"
echo ""

./vie arg1 arg2 arg3
echo $divider

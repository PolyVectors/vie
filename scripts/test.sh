declare -a args=("tests/test.asm" "-h" "--help")

for arg in "${args[@]}"
do
	echo "----------------------------------------"
	echo "running vie ${arg}"
	echo ""
	
	./vie "$arg"
done

echo "----------------------------------------"

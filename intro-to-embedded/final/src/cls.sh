PREVIOUS=$(cat platform.prev)
if [ "$1" != "$PREVIOUS" ]; then
rm -rf rm -f *.i *.o *.d *.out *.map *.asm
echo $1 > platform.prev
fi

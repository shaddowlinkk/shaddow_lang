echo "---Starting Testing---"
echo "---checking for test files--"
echo ""
echo "--test.sd--"
if test -f "test.sd"; then
	echo "test.sd exists: ✓"
else
	echo "test.sd exists: X"
	echo "-Making file-"
	echo "load test">test.sd
	echo "beep">>test.sd
	echo "boop">>test.sd
	if test -f "test.sd"; then
		echo "test.sd exists: ✓"
	else
		echo "test.sd exists: X"
		exit 1
	fi
fi

echo "--test.ini--"
if test -f "test.ini"; then
	echo "test.ini exists: ✓"
else
	echo "test.ini exists: X"
	echo "-Making file-"
	echo "[testing]">test.ini
	echo "test=this is a test">>test.ini
	if test -f "test.ini"; then
		echo "test.ini exists: ✓"
	else
		echo "test.ini exists: X"
		exit 1
	fi
fi
echo ""
echo "---ending file check---"
echo "---starting test of program---"
echo ""
echo "--parser--"

var="$(./$1 test test.sd)"
if [[ "$var" == "0::test:beep:boop:"  &&  $? == 10 ]]; then
	echo "Parser: ✓"
else
	echo "Parser: X"
fi

echo
echo "-- INI file Reader--"
var="$(./$1 INITesting)"
if [[ "$var" == "this is a test"  &&  $? == 11 ]]; then
	echo "INI Reader: ✓"
else
	echo "INI Reader: X"
fi

echo
echo "-- Action testing--"
var2="$(./$1 actionTesting)"
var=$?
if [[ $var == 12 ]]; then
	echo "Action testing: ✓"
else
	echo "Action testing: X"
	echo "error code:"${var}
fi
echo
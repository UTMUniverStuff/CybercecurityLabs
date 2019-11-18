#!/bin/bash

# Create matrix:
# Example: matrix <matrix_name> <dimension1> <dim2> ... <dim_n> 
matrix() {
	local dims=${@:2}
	
	if [[ ! $dims =~ ^([1-9][0-9]*([[:space:]]+|$))+$ ]]; then
		echo "Matrix: '$dims' bad dimensions"
		return 1
	fi

	declare -gA "$1"
	local -n "mat=$1"

	mat[dims]=$dims

	for index in `get_subscripts $1`; do
		mat[$index]=0
	done
}

# Creates a list of indexes.
# Example: get_subscripts <matrix_name>
# Output: 1,1 1,2 2,1 2,2
get_subscripts() {
	local -n "mat=$1"

	local s=""
	for i in ${mat[dims]}; do
		if [[ -z $s ]]; then
			sep=''
		else
			sep=','
		fi
		s="${s}$sep{0..$((i - 1))}"
	done

	eval echo $s
}

# Fill a matrix with a value
# Example: fill <matrix_name> <nb>
fill() {
	local val=$2
	for subscript in `get_subscripts $1`; do
		set $1 $subscript $val
	done
}

fillrand() {
	local start=$2
	local end=$3
	local diff=$((end - start))
	for subscript in `get_subscripts $1`; do
		set $1 $subscript $(((RANDOM % diff) + start))
	done
}

# Get item by index
# Example: get <matrix_name> 2,2
get() {
	local -n "mat=$1"

	subscript=$2
	el=${mat[$subscript]}
	if [[ -z $el ]]; then
		echo "Subscript: $subscript is bad index"
		return 1
	fi
	echo $el
}

# Example: set <matrix_name> 4,4,2 <value>
set() {
	local -n "mat=$1"
	subscript=$2
	val=$3
	if [[ ! $val =~ ^-?[0-9]+(.[0-9]+)?$ ]]; then
		echo "Set: $val is not a number"
		return 1
	fi
	if get $1 $subscript > /dev/null; then
		mat[$subscript]=$val
		return 0
	else
		return 1
	fi
}

# Example: out <matrix_name>
out() {
	local -n "mat=$1"
	for subscript in `get_subscripts $1`; do
		echo $1[$subscript]=`get $1 $subscript`
	done
}

# Applies an operation and saves the output into the given var
# Example: apply sum a + b
apply() {
	local -n "left=$2"
	local -n "right=$4"
	if [[ ! ${left[dims]} == ${right[dims]} ]]; then
		echo "Apply: dimensions didn't match"
		return 1
	fi
	matrix $1 ${left[dims]}
	local -n "result=$1"
	local op=$3

	for i in `get_subscripts $1`; do
		local left_val=${left[$i]}
		local right_val=${right[$i]}
		set $1 $i `echo "$left_val $op $right_val" | bc`
	done
}

# Reads the matrix values from stdin
input() {
	for s in `get_subscripts $1`; do
		while true; do
			echo -n $1[$s]=
			read val
			if set $1 $s $val > /dev/null; then
				break
			fi
		done
	done
}

while true; do
    echo -n "matrix $>";
    read line;
    eval $line;
done

let rec get_sum n =
	try
		let x = read_int () in
		if x mod 2 <> 0 then x + get_sum (n+1)
		else get_sum (n+1)
	with
	| End_of_file -> 0
;;

let () =
	let sum = get_sum 1 in
	print_endline (string_of_int sum)
;;
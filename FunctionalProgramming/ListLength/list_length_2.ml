let rec get_length sum =
	try
		let x = read_int () in
		get_length (sum+1)
	with
	| End_of_file -> sum
;;

let () =
	let n = get_length 0 in
	print_endline (string_of_int n)
;;
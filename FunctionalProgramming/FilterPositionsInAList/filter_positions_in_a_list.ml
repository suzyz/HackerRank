let rec get_list n =
	try
		let x = read_int () in
		if n mod 2 = 0 then x::(get_list (n+1))
		else get_list (n+1)
	with
	End_of_file -> []
;;

let print lst =
	List.map string_of_int lst
	|> String.concat "\n"
	|> print_endline
;;

let () =
	let lst = get_list 1 in
	print lst
;;
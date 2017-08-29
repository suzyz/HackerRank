
let rec get_lst n =
	try
		let x = read_int () in
		x :: (get_lst (n+1))
	with
	End_of_file -> []
;;

let rec rev lst =
	match lst with
	| [] -> []
	| h::t -> (rev t) @ [h]
;;

let print lst =
	List.map string_of_int lst
	|> String.concat "\n"
	|> print_endline
;;

let () =
	let lst = get_lst 1 in
	let lst2 = rev lst in
	print lst2
;;
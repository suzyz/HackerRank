let rec addAll arr = 
	match arr with
	| [] -> []
	| [a] -> []
	| h1::h2::t -> (h1+h2) :: addAll (h2::t)
;;

let printRes arr =
	List.map string_of_int arr
	|> String.concat " "
	|> Printf.printf "%s\n"
;;

let rec generate n =
	match n with
	| 0 -> [1]
	| _ -> let pre = generate (n-1) in
		   (1 :: (addAll pre) @ [1])
;;

let rec pascal n =
	if n>0 then pascal (n-1);

	printRes (generate n)
;;

let () =
	let n = read_int () in
		pascal (n-1)
;;
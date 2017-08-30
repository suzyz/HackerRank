let rec calc n =
	if n = 1 then
		Scanf.scanf "%d" (fun x -> x)
	else 
		let x = Scanf.scanf " %d " (fun x -> x) in
		x lxor calc (n-1)
;;

let () =
	let n = read_int () in
	let x = calc n in
	print_endline (string_of_int x)
;;
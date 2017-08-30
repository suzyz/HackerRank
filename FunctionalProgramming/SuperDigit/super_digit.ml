let rec get_super1 s i =
	if i = String.length s then 0
	else
		(int_of_char s.[i] - int_of_char '0') + (get_super1 s (i+1))
;;

let rec get_super n =
	if n < 10 then n
	else
		let d = n mod 10 in
		let r = n / 10 in
		d + get_super r
;;

let rec loop n =
	let m = get_super n in
	if m < 10 then m
	else loop m
;;

let () =
	let s = Scanf.scanf "%s" (fun x -> x) in
	let k = Scanf.scanf " %d" (fun x -> x) in
	let v = k * ( get_super1 s 0) in
	let res = loop v in
	print_endline (string_of_int res)
;;

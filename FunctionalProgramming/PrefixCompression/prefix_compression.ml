open Core.Std

let rec explode s i n =
	if i = n then []
	else
		s.[i] :: (explode s (i+1) n)
;;

let rec get_common_prefix x y = 
	match x with
	| [] -> []
	| hx::tx -> match y with
			| [] -> []
			| hy::ty -> if hx = hy then hx :: (get_common_prefix tx ty)
						else []
;;

let print l =
	let l2 = List.map Char.to_string l in
	let s = String.concat l2 in
		Printf.printf "%s\n" s
;;

let () =
	let x1 = Scanf.scanf " %s " (fun x -> x) in
	let y1 = Scanf.scanf " %s " (fun x -> x) in
	let x = explode x1 0 (String.length x1) in
	let y = explode y1 0 (String.length y1)  in
	let prefix = get_common_prefix x y in
		print prefix
		Printf.printf "%s\n" prefix
;;
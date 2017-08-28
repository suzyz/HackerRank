let explode s =
	let rec explo i l =
		if i<0 then l else
		explo (i-1) (s.[i] :: l) in 
	explo (String.length s -1) []
;;

let implode l =
	let res = String.create (List.length l) in
	let rec impl i = function
		|[] -> res
		|c::l -> res.[i] <- c; impl (i+1) l
	in impl 0 l
;;

let rec rotate s n =
	match s with
	| h::t -> let s2 = t @ [h] in
				let s3 = implode s2 in
				if n>1 then
				begin
					Printf.printf "%s " s3;
					rotate s2 (n-1)
				end
				else
					print_endline s3
	| _ -> print_endline ""		
;; 

let rec process t =
	let s = explode (read_line ()) in
	let n = (List.length s) in
	rotate s n;
	if t>1 then process (t-1)
;;

let () =
	let t = read_int () in
	process t
;;
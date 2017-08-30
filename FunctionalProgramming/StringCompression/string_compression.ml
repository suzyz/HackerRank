let rec count s i c =
	if i = String.length s then 0
	else
		if s.[i] = c then 1 + count s (i+1) c
		else 0
;;

let rec compress s i =
	if i = String.length s then ()
	else
		let n = count s i s.[i] in
 		if n = 1 then
		begin
			Printf.printf "%c" s.[i];
			compress s (i+1)
		end
		else
		begin
		 	Printf.printf "%c%d" s.[i] n;
			compress s (i+n)
		end
;;

let () =
	let s = read_line () in
	compress s 0;
	print_endline ""
;;
let rec get_length_of_common_prefix x y i = 
	if String.length x <= i || String.length y <= i then
		i
	else
		if x.[i] = y.[i] then
			get_length_of_common_prefix x y (i+1)
		else
			i
;;

let () =
	let x = Scanf.scanf " %s " (fun x -> x) in
	let y = Scanf.scanf " %s " (fun x -> x) in
	let prefix_length = get_length_of_common_prefix x y 0 in
		let prefix = String.sub x 0 prefix_length in
			Printf.printf "%d %s\n" prefix_length prefix;
			let len1 = (String.length x)-prefix_length in
			let len2 = (String.length y)-prefix_length in
			let x1 = String.sub x prefix_length len1 in
			let y1 = String.sub y prefix_length len2 in
				Printf.printf "%d %s\n%d %s\n" len1 x1 len2 y1
;;
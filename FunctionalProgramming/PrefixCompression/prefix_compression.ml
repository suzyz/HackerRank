let rec get_length_of_common_prefix x y i = 
	if List.length x <= i || List.length y <= i then
		i
	else
		if x.[i] = y.[i] then
			get_length_of_common_prefix x y (i+1)
		else
			i
;;

let print s st en =
	Printf.printf "%d " (en-st+1);
	if st <= en then
	(
		for i = st to en do
			Printf.printf "%c" s.[i]
		done
	);
	Printf.printf "\n"
;;

let () =
	let x = Scanf.scanf " %s " (fun x -> x) in
	let y = Scanf.scanf " %s " (fun x -> x) in
	let prefix_length = get_length_of_common_prefix x y 0 in
		print x 0 (prefix_length-1);
		print x prefix_length ((List.length x)-1);
		print y prefix_length ((List.length y)-1)
;;
let rec permute s m n =
	if m = n then ()
	else
	begin
		Printf.printf "%c%c" s.[m+1] s.[m];
		permute s (m+2) n
	end

let () =
	let t = read_int () in
	for i = 1 to t do
		let s = read_line () in
		let n = String.length s in
			permute s 0 n;
			Printf.printf "\n"
	done
;;
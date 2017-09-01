let rec print arr =
	for i = 0 to (Array.length arr - 1) do
		if i = (Array.length arr -1) then
 			Printf.printf "%d\n" arr.(i)
 		else
 			Printf.printf "%d " arr.(i)
 	done
;;

let rec move arr pos e =
	if pos < 0 || arr.(pos) < e then
	begin
		arr.(pos+1) <- e;
		print arr;
	end
	else
	begin
		arr.(pos+1) <- arr.(pos);
		print arr;
		move arr (pos-1) e
	end
;;

let () =
	let n = Scanf.scanf "%d " (fun x -> x) in
	let arr = Array.make n 0 in
		for i = 0 to (n-2) do
			let k = Scanf.scanf " %d " (fun x -> x) in
			arr.(i) <- k
		done;
		let e = Scanf.scanf " %d " (fun x -> x) in
		move arr (n-2) e;
;;

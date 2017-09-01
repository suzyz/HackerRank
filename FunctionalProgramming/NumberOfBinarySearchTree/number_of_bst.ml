let mo = 100000007;;

let rec find arr n =
	if arr.(n) > 0 then arr.(n)
	else
	begin
		arr.(n) <- 0;
		for i = 0 to (n-1) do
			let l = find arr i in
			let r = find arr (n-1-i) in
				arr.(n) <- (arr.(n) + l * r mod mo) mod mo
		done;
		arr.(n)
	end
;;		

let () =
	let arr = Array.make 1001 (-1) in
		arr.(0) <- 1;
		arr.(1) <- 1;
		let t = read_int () in
		for i = 1 to t do
			let n = read_int () in
			let res = find arr n in
			Printf.printf "%d\n" res
		done
;;
let find count k =
	let res = ref 0 in
	let sum = ref 0 in
	let flag = ref false in
	let i = ref 0 in
		while !flag = false && !i < 201 do
			sum := !sum + count.(!i);
			if !sum >= k then
			begin
				res := !i;
				flag := true
			end;
			i := !i + 1
		done;
		!res
;;

let find_2_median count d =
	if d mod 2 = 0 then
	(
		let a = find count (d/2) in
		let b = find count (d/2+1) in
			a + b
	)
	else 2 * find count ((d+1)/2)
;;

let () =
	let res = ref 0 in
	let count = Array.make 201 0 in
	let n = Scanf.scanf " %d " (fun x -> x) in
	let d = Scanf.scanf " %d " (fun x -> x) in
	let expend = Array.make n 0 in
		for i = 0 to (n-1) do
			let x = Scanf.scanf " %d " (fun x -> x) in
			(
				expend.(i) <- x;
				if i >= d then
				(
					let m = find_2_median count d in
						if x >= m then res := !res + 1;
					count.(expend.(i-d)) <- count.(expend.(i-d)) - 1;
				);
				count.(x) <- count.(x) + 1
			)
		done;
		Printf.printf "%d\n" !res
;;
		
let power i n =
	let p = ref i in
	for j = 1 to (n-1) do
		p := !p * i
	done;
	!p
;;

let rec find x last n =
	if x < 0 then 0
	else
		if x = 0 then 1
		else
		begin
			let res = ref 0 in
			let i = ref (last+1) in
			while (power !i n) <= x do
				res := !res + find (x - power !i n) !i n;
				i := !i + 1
			done;
			!res
		end
;;

let () =
	let x = read_int () in
	let n = read_int () in
	let res = find x 0 n in
		Printf.printf "%d\n" res
;;
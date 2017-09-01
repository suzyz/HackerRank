let () =
	let arr1 = Array.make 100 "" in
	let arr2 = Array.make 100 "" in
	let n = Scanf.scanf "%d " (fun x -> x) in
		for i = 1 to (n/2) do
			let x = Scanf.scanf " %d " (fun t -> t) in
			let y = Scanf.scanf " %s " (fun t -> t) in
			arr1.(x) <- arr1.(x)^"- "
		done;
		for i = (n/2+1) to n do
			let x = Scanf.scanf " %d " (fun t -> t) in
			let y = Scanf.scanf " %s " (fun t -> t) in
				arr2.(x) <- arr2.(x)^y^" "
		done;
		for i = 0 to 99 do
			if String.length arr1.(i) > 0 then
				Printf.printf "%s" arr1.(i);
			if String.length arr2.(i) > 0 then
				Printf.printf "%s" arr2.(i)
		done
;;
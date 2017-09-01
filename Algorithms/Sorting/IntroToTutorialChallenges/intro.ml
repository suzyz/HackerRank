let () =
   let v = Scanf.scanf " %d " (fun x -> x) in
   let n = Scanf.scanf " %d " (fun x -> x) in
   let res = ref 0 in
   let i = ref 0 in
	   while !i < n do
	   		let x = Scanf.scanf " %d " (fun x -> x) in
	   		if x = v then res := !i;
	   		i := !i + 1
	   done;
	   Printf.printf "%d\n" !res
;;

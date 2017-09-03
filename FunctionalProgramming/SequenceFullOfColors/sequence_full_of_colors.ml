
let check s n =
	let r = ref 0 in
	let g = ref 0 in
	let b = ref 0 in
	let y = ref 0 in
	let res = ref true in
	for i = 0 to (n-1) do
		match s.[i] with
		| 'R' -> r := !r + 1
		| 'G' -> g := !g + 1
		| 'B' -> b := !b + 1
		| 'Y' -> y := !y + 1
		;
		if abs (!r - !g) > 1 then res := false;
		if abs (!b - !y) > 1 then res := false
	done;
	if r <> g || b <> y then res := false;
	!res
;;

let () =
	let t = read_int () in
	for i = 1 to t do
		let s = read_line () in
		let n = String.length s in
		let res = check s n in
		if res then
			Printf.printf "True\n"
		else
			Printf.printf "False\n"
	done
;;
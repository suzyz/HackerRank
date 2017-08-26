let rec loop down space m n maxn =
    match m with
    | 0 -> down
    | _ -> if m<n then 
      	loop (List.map (fun x -> space ^ x ^ space) down @
              List.map (fun x -> x ^ "_" ^ x) down)
        (space ^ space)
        (m-1) (n-1) maxn

    else
    	loop (List.map (fun x -> space ^ x ^ space) down @
              List.map (fun x -> x ^ "1" ^ x) down)
        (space ^ space)
        (m-1) (n-1) maxn
;;

let sierpinski n =
   loop ["1"] "_" 5 n n
;;

let () =
	List.iter print_endline (sierpinski 1)
;;
(* 
let rec loop down space n =
    if n = 0 then
      down
    else
      loop (List.map (fun x -> space ^ x ^ space) down @
              List.map (fun x -> x ^ "_" ^ x) down)
        (space ^ space)
        (n - 1)
;;

let sierpinski n =
   loop ["1"] "_" n
;;

let () =
	List.iter print_endline (sierpinski 5)
;; *)
(* let concat_many = function
  | []      -> ""
  | x :: xs -> List.fold_left Filename.concat x xs

let () =
  Callback.register "sys_getcwd"  Sys.getcwd;
  Callback.register "concat"      Filename.concat;
  Callback.register "concat_many" concat_many *)
  
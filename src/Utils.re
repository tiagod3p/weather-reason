let s = React.string;

// binding require of javascript to requireImage
[@bs.val] external requireImage: string => string = "require";
[@bs.val] external requireCSS: string => unit = "require";

let ktoC = k => k -. 273.15;
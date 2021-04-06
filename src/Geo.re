let geo: option('a) = [%bs.raw {|navigator.geolocation|}];

[@bs.val]
external getCurrentPosition:
  (~onSuccess: 'a => unit, ~onError: 'b => unit) => unit =
  "navigator.geolocation.getCurrentPosition";

let getGeoLocation = (~sendGeo, ~sendErr) => {
  let onSuccess = position => sendGeo(position##coords##latitude, position##coords##longitude);
  let onError = e => sendErr(e);

  switch (geo) {
  | Some(_) => getCurrentPosition(~onSuccess, ~onError)
  | None => Js.log("None available")
  };
};

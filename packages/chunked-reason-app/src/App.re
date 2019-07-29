open ReasonUrql;

let client = Client.make(~url="https://formidadog-ql.now.sh", ());

module GetAllDogs = [%graphql
  {|
  query dogs {
    dogs {
      name
      breed
      likes
    }
  }
|}
];

let queryRequest = Request.createRequest(~query=GetAllDogs.make()##query, ());

type state = option(string);

[@react.component]
let make = () => {
  let (state, setState) = React.useState(_ => None);

  React.useEffect0(_ => {
    Client.executeQuery(~client, ~query=queryRequest, ())
    |> Wonka.forEach((. response) =>
         setState(_ => Some(Js.Json.stringifyWithSpace(response##data, 2)))
       );

    Some(() => ());
  });

  <div className="App">
    <React.Suspense fallback={<Loading />}>
      <LazyLogin.Lazy />
    </React.Suspense>
    <React.Suspense fallback={<Loading />}>
      <ComponentA.Lazy message="An async hello to you." />
    </React.Suspense>
    {switch (state) {
     | Some(state) =>
       <div>
         <h2> {React.string("Got some data, showing some stuff.")} </h2>
         <pre> {React.string(state)} </pre>
       </div>
     | None => React.null
     }}
  </div>;
};

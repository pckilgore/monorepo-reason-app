Auth.configure(Env.awsConfig);

type state = {
  username: string,
  password: string,
};

type loginFormActions =
  | UpdatePassword(string)
  | UpdateUsername(string);

let reducer = (state, action) =>
  switch (action) {
  | UpdatePassword(password) => {...state, password}
  | UpdateUsername(username) => {...state, username}
  | _ => state
  };

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(reducer, {username: "", password: ""});

  <div>
    <form>
      <input
        name="username"
        value={state.username}
        onChange={evt =>
          dispatch(UpdateUsername(evt->ReactEvent.Form.target##value))
        }
      />
      <input
        name="password"
        type_="password"
        value={state.password}
        onChange={evt =>
          dispatch(UpdatePassword(evt->ReactEvent.Form.target##value))
        }
      />
      <button
        onClick={event => {
          event->ReactEvent.Mouse.preventDefault;
          ignore(
            Auth.signIn(state.username, state.password, ())
            |> Js.Promise.then_(result => {
                 Js.log(result);
                 Js.Promise.resolve(result);
               }),
          );
        }}>
        {React.string("Submit Again!")}
      </button>
    </form>
  </div>;
};

let default = make;
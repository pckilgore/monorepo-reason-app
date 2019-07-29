// Import Auth.default as type auth
type auth;
[@bs.module "@aws-amplify/auth"] external auth: auth = "default";

// Build a function that will call the `configure` method of an object passed
// as the first argument.

type authenticationFlowType =
  | USER_SRP_AUTH
  | USER_PASSWORD_AUTH
  | CUSTOM_AUTH;

type cookieStorage = {
  domain: string,
  expires: int,
  secure: bool,
  path: string,
};

[@bs.deriving abstract]
type config = {
  [@bs.optional]
  identityPoolId: string,
  region: string,
  [@bs.optional]
  identityPoolRegion: string,
  userPoolId: string,
  userPoolWebClientId: string,
  [@bs.optional]
  mandatorySignIn: bool,
  [@bs.optional]
  cookieStorage,
  authenticationFlowType,
};

type validationData;

type signInOpts = {
  username: string,
  password: string,
  validationData: option(validationData),
};

type configure;
[@bs.send] external configure: (auth, config) => configure = "configure";
let configure = config => configure(auth, config);

[@bs.send]
external getCurrentSession: (auth, unit) => Js.Promise.t('a) =
  "currentSession";

[@bs.send]
external signIn:
  (auth, ~username: string, ~pw: string=?, unit) => Js.Promise.t('a) =
  "signIn";
let signIn = (username, pw) => signIn(auth, ~username, ~pw);

type user;
type oldPassword;
type newPassword;
[@bs.send]
external changePassword:
  (auth, user, oldPassword, newPassword) => Js.Promise.t('a) =
  "changePassword";
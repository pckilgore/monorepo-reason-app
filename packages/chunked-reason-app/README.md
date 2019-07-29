# reason-react-chunked

## What is this?

A reason-react example with code splitting / loadable components.

## How am I supposed to use it?

Import it and webpack it somewhere.  Might I suggest checking out the `web-app-mount` direcory for an example of how to do this with create-react-app?

## What else is there.

An example binding to an external library `@aws-amplify/auth`.   You  might notice that we're gitignoring and using `Env.re`'s `awsConfig` object, which is causing failed builds...

The code is mainly there as an example, but if you want to use it, the file would look like:
```reason
let awsConfig =
  Auth.config(
    // REQUIRED - Amazon Cognito Region
    ~region="us-east-2",
    // OPTIONAL - Amazon Cognito User Pool ID
    ~userPoolId="XX-XXXX-X_abcd1234",
    // OPTIONAL - Amazon Cognito Web Client ID (26-char alphanumeric string)
    ~userPoolWebClientId="a1b2c3d4e5f6g7h8i9j0k1l2m3",
    // OPTIONAL - Manually set the authentication flow type. Default is 'USER_SRP_AUTH'
    ~authenticationFlowType=USER_PASSWORD_AUTH,
    // etc...
    (), // Required because we are deriving abstract optional fields.
  );
```

At least with the above, it will build
# What is this project?

It is a monorepo example of a reason-app (with code splitting) that can consume components packaged separately in the repo. 

It uses create-react-app as a mount point for the reason app, allowing you to get most all the benefits of that ecosystem in a reason project.

This project is still a work in progress, especially the DX loop, but it certainly works.

#### What do the scripts/ do?

Lerna and bsb don't play well with each other in watch mode.  This postinstall script monkeypatches lerna to fix the error.  See https://github.com/BuckleScript/bucklescript/issues/2750#issuecomment-470537002.

#### What's the .tfbackend folder

I use terraform for infrastructure management and this is the boilerplate for a S3 backend for terraform.  If you don't want to use terraform, it can be safely deleted with no effect on the reason/react aspects of this repo.

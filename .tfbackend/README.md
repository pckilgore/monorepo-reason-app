# Terraform Management

These files manage the resources where the remote state for the actual application infrastructure is stored.

To avoid an infinite loop, we keep the local state for this project in git.

Normally this is a bad idea, as the `tfstate` file can contain keys, and moreover, you have to remember to check them in after running `.tfapply` or risk mismatched state across contributors and multiple backend pushes creating state conflicts due to gits distributed nature we cannot create a single lockfile across contributors (which is why we don't use some sort of 'git-backend' for the real project).

But these TF state files should _never_ contain keys (which are safely stored in out build-system environment files), and this config should never change (which is why we aren't worrying about state/lockfiles issues).

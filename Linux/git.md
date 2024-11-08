# Github commands
very good documentation on: https://www.atlassian.com/git/tutorials/

## Global

### setting your account's global identity:
``` bash
git config --global user.email "you@example.com"
git config --global user.name "Your Name"
```

### [Creating an SSH key](https://docs.github.com/en/github/authenticating-to-github/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent)

1. `$ ssh-keygen -t ed25519 -C "your_email@example.com"`
2. When you're prompted to "Enter a file in which to save the key," press Enter. This accepts the default file location.
3. At the prompt, type a secure passphrase. 

### adding SSH-key to account:
https://help.github.com/en/github/authenticating-to-github/connecting-to-github-with-ssh

https://docs.github.com/en/authentication/connecting-to-github-with-ssh/adding-a-new-ssh-key-to-your-github-account

**[never be asked for password again!](https://stackoverflow.com/questions/21095054/ssh-key-still-asking-for-password-and-passphrase)**

1. check for existing SSH key:
`ls -al ~/.ssh` --> contains `id_rsa, id_rsa.pub, ...`?

2. add key to ssh-agent
``` bash
$ eval "$(ssh-agent -s)"
> Agent pid 59566
$ ssh-add ~/.ssh/id_[rsa]
```

bzw `ssh-add /.ssh/id_ed25519`, wenn der generierte Key ein anderer ist

3. copy and add to github
`cat ./ssh/id_rsa.pub` --> github>settings>SSH&GPG keys>new SSH key>add.

4. Switching remote URLs from HTTPS to SSH
``` bash
$ git remote -v
> origin  https://github.com/USERNAME/REPOSITORY.git (fetch)
> origin  https://github.com/USERNAME/REPOSITORY.git (push)

$ git remote set-url origin git@github.com:USERNAME/REPOSITORY.git
```

### permanently add ssh-key in kde:

https://www.techrepublic.com/article/use-kde-plasmas-konsole-ssh-plugin/

## Repositories

### add, commit, push

`git add XY` - adds file to commit  
`git rm --cached XY` - removes file from commit  
`git commit -m "bla"` - creates commit named _bla_  

**show differences in commit** (and its' parent):

``` bash
git log --oneline # shows commit hashes
git diff COMMIT~ COMMIT
```

### push to another server

- `git remote add [name] [user@ip.adress:repos/repo]`
- `git push [name] [branch]`
### submodules

#### clone git with submodules
`git clone --recursive https://github.com/sonydevworld/spresense.git`  
After repositories have been cloned, each submodule is in 'Detached HEAD' state. Master branch have to be checked out before you can start developing.  
`git submodule foreach git checkout master`

#### adding existing repo as submodule
https://git-scm.com/book/en/v2/Git-Tools-Submodules

use `git submodule add`:

``` bash
$ git submodule add https://github.com/chaconinc/DbConnector
Cloning into 'DbConnector'...
remote: Counting objects: 11, done.
remote: Compressing objects: 100% (10/10), done.
remote: Total 11 (delta 0), reused 11 (delta 0)
Unpacking objects: 100% (11/11), done.
Checking connectivity... done.
```

### create repo from folder:  
``` bash
git init
git add .
git commit -m "<commit message>"
# create repo online, then:  
git remote add origin <url>
git pull origin main --allow-unrelated-histories
git push -u origin master
``` 

**irgendwas hiermit ist falsch, da der branch "master" ja eigentlich gar nicht mehr benutzt werden soll!!**`

### switch branch
Switching from master to "Areaplot". **Case-sensitive**!

``` bash
git checkout -b Areaplot
git branch --set-upstream-to=origin/Areaplot Areaplot
git fetch
git pull
```

### merging branches

1. prepare by switching to receiving branch
2. check for remote changes: fetch & pull
3. merge

``` bash
git checkout main
git fetch
git pull
git merge otherBranch
```

### use USB drive as remote

``` bash
git init --bare /media/user/device/repo
cd /to/local/repo
git remote add usb /media/user/device/repo
git checkout main
git push usb main
```
### change upstream after transfering repo to another URL

`git remote show origin` shows current URL  
`git remote set-url origin new.git.url/here` sets URL
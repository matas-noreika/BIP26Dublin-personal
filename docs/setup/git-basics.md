# Git Basics

Git is version control software. It keeps track of project changes and allows a team to work on the same project without manually passing files around.

GitHub is the online platform used to store the repository.

In simple terms:

| Tool           | Purpose                                                            |
| -------------- | ------------------------------------------------------------------ |
| Git            | Tracks changes on your computer                                    |
| GitHub         | Stores the repository online                                       |
| GitHub Desktop | Provides a visual interface for Git                                |
| Git CLI        | Allows Git to be used from the terminal                            |
| GitHub CLI     | Optional tool for GitHub features such as pull requests and issues |

For beginners, GitHub Desktop is usually the easiest option. The Git command line is useful later because it gives more control and is commonly used in software projects.

## Recommended Workflow

For this programme, a good beginner workflow is:

```text
GitHub Desktop + Arduino IDE
```

Use GitHub Desktop to:

* Clone repositories
* Create branches
* View changed files
* Commit changes
* Push changes
* Open pull requests

Use Arduino IDE to:

* Open `.ino` sketches
* Compile code
* Upload code to the board
* Use Serial Monitor for debugging

!!! tip
Arduino IDE edits the code files. GitHub Desktop or Git CLI is used afterwards to save and upload those changes.

## Creating a GitHub Account

Create a GitHub account here:

<a href="https://github.com/signup" target="_blank" rel="noopener noreferrer">Create a GitHub account</a>

After creating an account:

1. Verify your email address.
2. Choose a username that teammates can recognise.
3. Ask the repository owner to add you as a collaborator, or fork the repository if you are contributing to someone else's project.

A good username is short and readable.

Example:

```text
student-name
project-name
name-project
```

Avoid spaces in usernames.

## Installing GitHub Desktop

Download GitHub Desktop here:

<a href="https://desktop.github.com/" target="_blank" rel="noopener noreferrer">Download GitHub Desktop</a>

GitHub Desktop is a good starting point for students because it shows changed files clearly and avoids needing to remember commands at the beginning.

After installing:

1. Open GitHub Desktop.
2. Sign in using your GitHub account.
3. Choose a local folder where repositories should be stored.

A common folder location is:

```text
Documents/GitHub/
```

## Cloning a Repository With GitHub Desktop

Cloning means downloading a copy of the repository to your computer.

Useful reference:

<a href="https://docs.github.com/articles/cloning-a-repository" target="_blank" rel="noopener noreferrer">Cloning a repository</a>

In GitHub Desktop:

1. Select **File → Clone Repository**.
2. Choose the repository or paste the repository URL.
3. Choose a local folder.
4. Click **Clone**.

After cloning, the project files are now on your computer.

## Pulling Latest Changes

Before editing, always pull the latest version.

In GitHub Desktop:

```text
Fetch origin → Pull origin
```

This downloads changes made by other team members.

!!! warning
Pull before starting work. This reduces the chance of working on an old version of the project.

## Creating a Branch

A branch is a safe workspace for your changes.

Use clear branch names:

```text
add-arduino-setup
update-git-basics
fix-sensor-notes
add-gnss-example
```

In GitHub Desktop:

1. Click the current branch name.
2. Click **New Branch**.
3. Enter a branch name.
4. Click **Create Branch**.

Avoid working directly on `main` unless the team has agreed to it.

## Making Changes

After creating a branch:

1. Open the repository folder.
2. Edit the required files.
3. Save the files.
4. Test the changes if they include code.

For documentation, edit Markdown files such as:

```text
docs/setup/git-basics.md
docs/setup/arduino-ide.md
```

For Arduino code, open the `.ino` file in Arduino IDE.

## Committing Changes

A commit is a saved checkpoint.

In GitHub Desktop:

1. Review the changed files.
2. Write a short commit message.
3. Click **Commit to branch-name**.

Good commit messages:

```text
Add Arduino IDE setup guide
Update Git basics page
Fix sensor setup notes
Add GNSS test sketch
```

Avoid unclear messages:

```text
stuff
changes
update
fixed things
```

## Pushing Changes

Pushing uploads your commits to GitHub.

Useful reference:

<a href="https://docs.github.com/en/desktop/making-changes-in-a-branch/pushing-changes-to-github-from-github-desktop" target="_blank" rel="noopener noreferrer">Pushing changes to GitHub from GitHub Desktop</a>

In GitHub Desktop, click:

```text
Push origin
```

If the branch is new, GitHub Desktop may show:

```text
Publish branch
```

Click it.

## Opening a Pull Request

A pull request asks the project owner to review and merge your changes.

Useful reference:

<a href="https://docs.github.com/en/desktop/working-with-your-remote-repository-on-github-or-github-enterprise/creating-an-issue-or-pull-request-from-github-desktop" target="_blank" rel="noopener noreferrer">Creating a pull request from GitHub Desktop</a>

In GitHub Desktop:

```text
Branch → Create Pull Request
```

A useful pull request description includes:

* What was changed
* Why it was changed
* How it was tested
* Anything that still needs review

Example:

```text
Added setup instructions for Arduino IDE and Git basics.

Tested:
- Previewed the documentation site locally
- Checked page formatting
- Checked links and code blocks
```

## Installing Git CLI

Git CLI means using Git from the terminal.

Download Git here:

<a href="https://git-scm.com/downloads" target="_blank" rel="noopener noreferrer">Download Git</a>

After installing, check that Git is available:

```bash
git --version
```

## Setting Up Git CLI

Set your name:

```bash
git config --global user.name "Your Name"
```

Set your email:

```bash
git config --global user.email "your-email@example.com"
```

Check the saved details:

```bash
git config --global user.name
git config --global user.email
```

These details are attached to future commits.

Useful reference:

<a href="https://docs.github.com/en/get-started/git-basics/set-up-git" target="_blank" rel="noopener noreferrer">Set up Git</a>

## Cloning With Git CLI

Clone a repository:

```bash
git clone https://github.com/username/repository-name.git
```

Enter the repository folder:

```bash
cd repository-name
```

Check the current branch and status:

```bash
git status
```

## Basic Git CLI Workflow

Before starting work, update your local copy:

```bash
git pull
```

Create a new branch:

```bash
git checkout -b add-setup-notes
```

Check changed files:

```bash
git status
```

Stage files:

```bash
git add docs/setup/arduino-ide.md
git add docs/setup/git-basics.md
```

Commit the staged changes:

```bash
git commit -m "Add setup documentation"
```

Push the branch:

```bash
git push -u origin add-setup-notes
```

Then open a pull request on GitHub.

## Useful Git Commands

| Command                       | Meaning                              |
| ----------------------------- | ------------------------------------ |
| `git status`                  | Shows changed files                  |
| `git pull`                    | Downloads the latest changes         |
| `git add file.md`             | Stages a file for commit             |
| `git commit -m "message"`     | Saves a checkpoint                   |
| `git push`                    | Uploads commits to GitHub            |
| `git branch`                  | Shows local branches                 |
| `git checkout -b branch-name` | Creates and switches to a new branch |
| `git diff`                    | Shows line-by-line changes           |
| `git log --oneline`           | Shows recent commit history          |

## Common Problems

| Problem                          | Cause                                     | Fix                                            |
| -------------------------------- | ----------------------------------------- | ---------------------------------------------- |
| Push rejected                    | Someone else changed the repo first       | Run `git pull`, then try again                 |
| Wrong branch                     | Work was done on `main` by mistake        | Create a new branch before continuing          |
| Old commit name                  | Git user details are outdated             | Update `git config --global user.name`         |
| Merge conflict                   | Two people edited the same lines          | Choose the correct version, save, commit again |
| Arduino sketch opens incorrectly | Folder and `.ino` file names do not match | Rename the folder and `.ino` file to match     |

## Other Options

GitHub Desktop is the best beginner option for most students.

Other tools can also be useful:

| Tool                   | When It Is Useful                                                                 |
| ---------------------- | --------------------------------------------------------------------------------- |
| VS Code Source Control | Good if students already use VS Code                                              |
| Git CLI                | Best for learning professional Git workflow                                       |
| GitHub CLI             | Useful for advanced GitHub tasks                                                  |
| GitHub web editor      | Useful for quick documentation edits                                              |
| Arduino Cloud Editor   | Useful for browser-based Arduino work, but less ideal for shared GitHub workflows |

For hardware projects, the most reliable workflow is still:

```text
Clone repository → Edit locally → Test on hardware → Commit → Push → Pull request
```

# Hacktoberfest2020-Algorithms
![Hacktoberfest Banner](https://i.ibb.co/4FjRdbH/Logo-Sponsors-Light.png)
### What you can do with this repo ?
You can add a new folder for your favourite programming (if not already present) language and start adding algorithms to the folder.

### Steps to contribute
0. Star this repository.
1. Click on the fork button on the top right corner of this page.
2. Now go to http://github.com/{your_username}/hacktoberfest2020-algorithms where you can see your own fork of this repo.
3. Open the terminal and clone your fork using
  ```
  git clone http://github.com/{your_username}/hacktoberfest2020-algorithms
  ```
4. Before you make any changes, [keep your fork in sync](https://www.freecodecamp.org/news/how-to-sync-your-fork-with-the-original-git-repository/) to avoid merge conflicts:

    ```bash
    git remote add upstream https://github.com/zero-to-mastery/start-here-guidelines.git
    git pull upstream master
    ```

    If you run into a **merge conflict**, you have to resolve the conflict. There are a lot of guides online, or you can try this one by [opensource.com](https://opensource.com/article/20/4/git-merge-conflict).

5. Now go inside the directory "hacktoberfest2020-algorithms" and checkout to a new branch with name of your choice
  ```
  git checkout -b {branch_name}
  ```
6. Start adding/modifying your algorithms.
7. Add the files you want to commit to the staging area.
  ```
  git add {folder_name/file_name}
  ```
8. Commit the changes
  ```
  git commit -m '{Your commit message}'
  ```
9. Push to GitHub.
  ```
  git push origin {branch_name}
  ```
10. Go to http://github.com/{your_username}/hacktoberfest2020-algorithms , on the left there is a button to change your branch. Click on it and select {branch_name}.
11. Now you will be able see a button named "Pull request". Click on it.
12. Add appropriate message and click the "Create Pull Request" button.

#### Resolving errors
1. If you get a message like "This branch is X commits ahead, Y commits behind" then visit [this](https://stackoverflow.com/questions/41283955/github-keeps-saying-this-branch-is-x-commits-ahead-y-commits-behind/41289258) thread and follow the steps. Also don't forget to push and pull from proper branches (observe that we have a main branch instead of master).
2. In case of merge conflict visit [this](https://stackoverflow.com/questions/161813/how-to-resolve-merge-conflicts-in-git) thread.

# 📤 How to Upload to GitHub

Follow these simple steps to upload your project to GitHub so others can access and download it.

## Step 1: Create GitHub Account (if you don't have one)

1. Go to [github.com](https://github.com)
2. Click "Sign up"
3. Create your account

## Step 2: Create a New Repository

1. After logging in, click the **"+"** icon in the top right
2. Select **"New repository"**
3. Fill in:
   - **Repository name**: `data-structure-visualizer` (or any name you like)
   - **Description**: "Web-based visualizer for Arrays, Linked Lists, Stacks, and Queues"
   - **Visibility**: Choose **Public** (so others can see and download)
   - **DO NOT** check "Initialize with README" (we already have one)
4. Click **"Create repository"**

## Step 3: Install Git (if not installed)

### Windows:
1. Download from: [git-scm.com/download/win](https://git-scm.com/download/win)
2. Install with default settings
3. Open **Git Bash** or **PowerShell**

### Check if Git is installed:
```bash
git --version
```

## Step 4: Upload Your Code

Open **PowerShell** or **Command Prompt** in your project folder and run:

```bash
# Initialize Git repository
git init

# Add all files
git add .

# Create first commit
git commit -m "Initial commit: Data Structure Visualizer"

# Rename branch to main (if needed)
git branch -M main

# Add your GitHub repository (replace YOUR_USERNAME with your GitHub username)
git remote add origin https://github.com/YOUR_USERNAME/data-structure-visualizer.git

# Push to GitHub
git push -u origin main
```

**Note**: You'll be asked for your GitHub username and password (or Personal Access Token).

## Step 5: Get Personal Access Token (if needed)

If password doesn't work:

1. Go to GitHub → Settings → Developer settings → Personal access tokens → Tokens (classic)
2. Click "Generate new token"
3. Give it a name: "Data Structure Visualizer"
4. Select scopes: Check **"repo"** (full control)
5. Click "Generate token"
6. **Copy the token** (you won't see it again!)
7. Use this token as your password when pushing

## Step 6: Verify Upload

1. Go to your GitHub repository page
2. You should see all your files
3. Click the green **"Code"** button
4. You'll see options to:
   - Clone the repository
   - Download ZIP file

## Step 7: Share Your Repository

Share these links:

1. **Repository Link**: `https://github.com/YOUR_USERNAME/data-structure-visualizer`
2. **Download ZIP**: `https://github.com/YOUR_USERNAME/data-structure-visualizer/archive/refs/heads/main.zip`

## 🎉 Done!

Your code is now on GitHub! Others can:
- ✅ View your code online
- ✅ Download as ZIP file
- ✅ Clone the repository
- ✅ Star and fork your project

## 📝 Future Updates

When you make changes, update GitHub with:

```bash
git add .
git commit -m "Description of changes"
git push
```

## 🔗 Next Steps: Host Online

To make the website accessible online (not just downloadable), see [HOSTING.md](HOSTING.md) for hosting options.

---

**Need Help?**
- Git documentation: [git-scm.com/docs](https://git-scm.com/docs)
- GitHub Guides: [guides.github.com](https://guides.github.com)


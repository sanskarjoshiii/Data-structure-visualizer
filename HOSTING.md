# 🌐 Hosting Guide

This guide explains how to host the Data Structure Visualizer online so others can access it via a web link.

## ⚠️ Important Note

Since this is a **C++ backend application** (not a static website), **GitHub Pages cannot host it directly**. GitHub Pages only supports static HTML/CSS/JavaScript files.

## 🎯 Hosting Options

### Option 1: Free Cloud Platforms (Recommended)

#### A. Render.com (Free Tier Available)
1. Create account at [render.com](https://render.com)
2. Create a new "Web Service"
3. Connect your GitHub repository
4. Build command: `g++ src/main.cpp src/linked_list.cpp src/data_structures.cpp -std=c++17 -I./external/Crow/include -I./external/asio/include -o dsa_visualizer -pthread -DASIO_STANDALONE`
5. Start command: `./dsa_visualizer`
6. Set environment: Docker or Native

#### B. Railway.app (Free Tier Available)
1. Sign up at [railway.app](https://railway.app)
2. New Project → Deploy from GitHub
3. Select your repository
4. Configure build and start commands
5. Deploy!

#### C. Heroku (Requires Credit Card, but free tier available)
1. Install Heroku CLI
2. Create `Procfile`:
   ```
   web: ./dsa_visualizer
   ```
3. Create `app.json` for build configuration
4. Deploy using Heroku CLI

### Option 2: VPS (Virtual Private Server)

#### Recommended Providers:
- **DigitalOcean** ($5/month)
- **Linode** ($5/month)
- **AWS EC2** (Free tier available)
- **Google Cloud Platform** (Free tier available)
- **Azure** (Free tier available)

#### Steps:
1. Create a VPS instance (Ubuntu recommended)
2. SSH into the server
3. Install dependencies:
   ```bash
   sudo apt update
   sudo apt install build-essential git
   ```
4. Clone your repository:
   ```bash
   git clone https://github.com/YOUR_USERNAME/data-structure-visualizer.git
   cd data-structure-visualizer
   ```
5. Build the project:
   ```bash
   g++ src/main.cpp src/linked_list.cpp src/data_structures.cpp -std=c++17 \
       -I./external/Crow/include -I./external/asio/include \
       -o dsa_visualizer -pthread -DASIO_STANDALONE
   ```
6. Run with screen or systemd:
   ```bash
   screen -S dsa
   ./dsa_visualizer
   # Press Ctrl+A then D to detach
   ```
7. Configure firewall:
   ```bash
   sudo ufw allow 18080
   ```
8. Access via: `http://YOUR_SERVER_IP:18080`

### Option 3: Docker (Recommended for Easy Deployment)

1. Create `Dockerfile`:
   ```dockerfile
   FROM ubuntu:22.04
   
   RUN apt-get update && apt-get install -y \
       build-essential \
       && rm -rf /var/lib/apt/lists/*
   
   WORKDIR /app
   COPY . .
   
   RUN g++ src/main.cpp src/linked_list.cpp src/data_structures.cpp -std=c++17 \
       -I./external/Crow/include -I./external/asio/include \
       -o dsa_visualizer -pthread -DASIO_STANDALONE
   
   EXPOSE 18080
   CMD ["./dsa_visualizer"]
   ```

2. Build and run:
   ```bash
   docker build -t dsa-visualizer .
   docker run -p 18080:18080 dsa-visualizer
   ```

3. Deploy to:
   - **Docker Hub** + Any cloud provider
   - **Railway.app** (supports Docker)
   - **Fly.io** (supports Docker)
   - **Google Cloud Run** (supports Docker)

### Option 4: Static Frontend Only (Limited Functionality)

If you want to use GitHub Pages, you'd need to:
1. Convert backend to a separate API service
2. Host frontend on GitHub Pages
3. Point frontend to your API URL

This requires significant refactoring.

## 📦 Making Code Downloadable on GitHub

Your code is **already downloadable** on GitHub! Users can:

1. **Download as ZIP**:
   - Click the green "Code" button
   - Select "Download ZIP"

2. **Clone via Git**:
   ```bash
   git clone https://github.com/YOUR_USERNAME/data-structure-visualizer.git
   ```

## 🚀 Quick Setup for GitHub Repository

1. **Create GitHub Repository**:
   - Go to [github.com](https://github.com)
   - Click "New repository"
   - Name it: `data-structure-visualizer`
   - Make it Public (so others can download)
   - Don't initialize with README (we already have one)

2. **Push Your Code**:
   ```bash
   git init
   git add .
   git commit -m "Initial commit: Data Structure Visualizer"
   git branch -M main
   git remote add origin https://github.com/YOUR_USERNAME/data-structure-visualizer.git
   git push -u origin main
   ```

3. **Add Repository Description**:
   - Go to repository settings
   - Add description: "Web-based visualizer for Arrays, Linked Lists, Stacks, and Queues"

## 🔗 Sharing Your Hosted Application

Once hosted, share:
- **Live Link**: `http://your-domain.com:18080` or `https://your-app.railway.app`
- **GitHub Repository**: `https://github.com/YOUR_USERNAME/data-structure-visualizer`
- **Download Instructions**: Mention in README that users can download ZIP

## 📝 Example README Addition

Add this to your README:

```markdown
## 🌐 Live Demo

Try it online: [https://your-app.railway.app](https://your-app.railway.app)

## 📥 Download

- **Download ZIP**: Click the green "Code" button → "Download ZIP"
- **Clone**: `git clone https://github.com/YOUR_USERNAME/data-structure-visualizer.git`
```

## 💡 Recommended Approach

For easiest hosting:
1. **Use Railway.app or Render.com** (free tier, easy setup)
2. **Connect GitHub repository** (automatic deployments)
3. **Share the live link** in your README

This gives you:
- ✅ Free hosting
- ✅ Automatic deployments
- ✅ Public access via link
- ✅ Code downloadable from GitHub

---

**Need help?** Open an issue on GitHub or check the platform's documentation!


const $ = document.querySelector.bind(document);
const $$ = document.querySelectorAll.bind(document);
const PLAYER_STORAGE_KEY = '"APP_KEY"';
const heading = $('header h2');
const cdthumb = $('.cd-thumb');
const audio = $('#audio');
const cd = $('.cd');
const player = $('.player');
const playBtn = $('.btn-toggle-play');
const progress = $('#progress');
const preBtn = $('.btn-prev');
const nextBtn = $('.btn-next');
const repeatBtn = $('.btn-repeat');
const randomBtn = $('.btn-random');
const playList = $('.playlist');
const app = {
  currentIndex: 0,
  isPlaying: false,
  isRandom: false,
  isRepeat: false,
  config:  JSON.parse(localStorage.getItem(PLAYER_STORAGE_KEY))||{},
  songs: [
    {
      name: 'Ghệ iu dấu của em ơi',
      singer: 'Tlinh',
      path: './music/GheIuDauCuaEmOiftHong-tlinhHong-9613041.mp3',
      img: './image/GID.jpg',
    },
    {
      name: 'Dự báo thời tiết hôm nay mưa',
      singer: 'GreyD',
      path: './music/DuBaoThoiTietHomNayMua-GREYD-8255553.mp3',
      img: './image/loi-bai-hat-du-bao-thoi-tiet-hom-nay-mua-grey-d-200.jpg',
    },
    {
      name: 'Mưa tháng sáu',
      singer: 'Văn Mai Hương',
      path: './music/MuaThangSau-VanMaiHuongGREYDTrungQuanIdol-9534954.mp3',
      img: './image/mt6.jpg',
    },
    {
      name: 'Vài câu nói có khiên người thay đổi',
      singer: 'GreyD,Tlinh',
      path: './music/Vaicaunoicokhiennguoithaydoi-GREYDDoanTheLanTlinh-7533673.mp3',
      img: './image/vcnckntd.jpg',
    },
    {
      name: 'Đưa em về nhà',
      singer: 'GreyD',
      path: './music/DuaEmVeNhaa-GREYDChillies-9214678.mp3',
      img: './image/DEVN.jpg',
    },
  ],
  setConfig:function(key,value){
    this.config[key]=value
    localStorage.setItem(PLAYER_STORAGE_KEY,JSON.stringify(this.config))
  },
  render: function() {
    const htmls = this.songs.map((song, index) => {
      return `
        <div class="song ${index === this.currentIndex ? 'active' : ''}" data-index="${index}">
          <div class="thumb" style="background-image: url('${song.img}')"></div>
          <div class="body">
            <h3 class="title">${song.name}</h3>
            <p class="author">${song.singer}</p>
          </div>
          <div class="option">
            <i class="fas fa-ellipsis-h"></i>
          </div>
        </div>
      `;
    });
    playList.innerHTML = htmls.join('');
  },

  defineProperties: function() {
    Object.defineProperty(this, 'currentSong', {
      get: function() {
        return this.songs[this.currentIndex];
      },
    });
  },

  handleEvent: function() {
    const cdWidth = cd.offsetWidth;

    // Xử lý phóng to / thu nhỏ CD
    document.onscroll = function() {
      const scrollTop = window.scrollY || document.documentElement.scrollTop;
      const newCdWidth = cdWidth - scrollTop;

      cd.style.width = newCdWidth > 0 ? newCdWidth + 'px' : 0;
      cd.style.opacity = newCdWidth / cdWidth;
    };

    // Xử lý khi click play
    playBtn.onclick = function() {
      if (app.isPlaying) {
        audio.pause();
      } else {
        audio.play();
      }
    };

    // Khi song được play
    audio.onplay = function() {
      app.isPlaying = true;
      player.classList.add('playing');
      cdthumb.classList.add('playing');
    };

    // Khi song bị pause
    audio.onpause = function() {
      app.isPlaying = false;
      player.classList.remove('playing');
      cdthumb.classList.remove('playing');
    };

    // Khi tiến độ bài hát thay đổi
    audio.ontimeupdate = function() {
      if (audio.duration) {
        const progressPercent = Math.floor((audio.currentTime / audio.duration) * 100);
        progress.value = progressPercent;
      }
    };

    // Xử lý khi tua song
    progress.oninput = function(e) {
      const seekTime = (audio.duration / 100) * e.target.value;
      audio.currentTime = seekTime;
    };

    // Khi next song
    nextBtn.onclick = function() {
      if (app.isRandom) {
        app.playRandomSong();
      } else {
        app.nextSong();
      }
      audio.play();
      app.render();
      app.scrollToActiveSong();
    };

    // Khi prev song
    preBtn.onclick = function() {
      if (app.isRandom) {
        app.playRandomSong();
      } else {
        app.prevSong();
      }
      audio.play();
      app.render();
      app.scrollToActiveSong();
    };

    // Xử lý bật / tắt random song
    randomBtn.onclick = function(e) {
      app.isRandom = !app.isRandom;
      app.setConfig('isRandom',app.isRandom)
      randomBtn.classList.toggle('active', app.isRandom);
      
    };

    // Xử lý lặp lại một song
    repeatBtn.onclick = function(e) {
      app.isRepeat = !app.isRepeat;
      app.setConfig('isRepeat',app.isRepeat)
      repeatBtn.classList.toggle('active', app.isRepeat);
     
    };

    // Xử lý next song khi audio ended
    audio.onended = function() {
      if (app.isRepeat) {
        audio.play();
      } else {
        nextBtn.click();
      }
    };

    // Lắng nghe hành vi click vào playlist
    playList.onclick = function(e) {
      const songNode = e.target.closest('.song:not(.active)');
      if (songNode || e.target.closest('.option')) {
        // Xử lý khi click vào song
        if (songNode) {
          app.currentIndex = Number(songNode.dataset.index);
          app.loadCurrentSong();
          audio.play();
          app.render();
        }
        // Xử lý khi click vào option
        if (e.target.closest('.option')) {
          console.log('Option');
        }
      }
    };
  },

  scrollToActiveSong: function() {
    setTimeout(() => {
      $('.song.active').scrollIntoView({
        behavior: 'smooth',
        block: 'nearest',
      });
    }, 300);
  },

  loadCurrentSong: function() {
    heading.textContent = this.currentSong.name;
    cdthumb.style.backgroundImage = `url('${this.currentSong.img}')`;
    audio.src = this.currentSong.path;
  },
 loadConfig:function(){
    this.isRandom= this.config.isRandom
    this.isRepeat=this.config.isRepeat
 },
  nextSong: function() {
    this.currentIndex++;
    if (this.currentIndex >= this.songs.length) {
      this.currentIndex = 0;
    }
    this.loadCurrentSong();
  },

  prevSong: function() {
    this.currentIndex--;
    if (this.currentIndex < 0) {
      this.currentIndex = this.songs.length - 1;
    }
    this.loadCurrentSong();
  },

  playRandomSong: function() {
    let newIndex;
    do {
      newIndex = Math.floor(Math.random() * this.songs.length);
    } while (newIndex === this.currentIndex);
    this.currentIndex = newIndex;
    this.loadCurrentSong();
  },

  start: function() {
    //Gán cấu hình từ config vào ứng dụng
    this.loadConfig()
    // Định nghĩa các thuộc tính cho object
    this.defineProperties();

    // Lắng nghe / xử lý các sự kiện (DOM events)
    this.handleEvent();

    // Tải thông tin bài hát đầu tiên vào UI khi chạy ứng dụng
    this.loadCurrentSong();

    // Render playlist
    this.render();
    // Hiển hị trạng thái ban đầu của button repeat và random
    repeatBtn.classList.toggle('active', this.isRepeat);
      randomBtn.classList.toggle('active', this.isRandom);
  },
};

app.start();

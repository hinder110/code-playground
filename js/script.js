console.log("hallow world");

// 等待DOM加载完成
document.addEventListener('DOMContentLoaded', function () {
    // 获取DOM元素
    const homeSection = document.getElementById('home');
    const aboutSection = document.getElementById('about');
    const contactSection = document.getElementById('contact');
    const mySection = document.getElementById('my');
    const toggleButton = document.createElement('button');
    const dynamicText = document.createElement('p');
    //这里是联系了DOM的元素的！！！我自己设置一个元素试一下

    // 设置按钮和动态文本
    toggleButton.textContent = '这是一个按钮，关联上面的常量';
    dynamicText.textContent = '这是动态加载的内容！';
    dynamicText.style.display = 'none'; // 初始隐藏

    // 将按钮和动态文本添加到首页部分
    homeSection.appendChild(toggleButton);
    homeSection.appendChild(dynamicText);
    mySection.appendChild(dynamicText);

    // 按钮点击事件
    toggleButton.addEventListener('click', function () {
        if (dynamicText.style.display === 'none') {
            dynamicText.style.display = 'block';
            toggleButton.textContent = '隐藏内容';
        } else {
            dynamicText.style.display = 'none';
            toggleButton.textContent = '显示更多内容';
        }
    });

    // 动态更改关于部分的内容
    aboutSection.addEventListener('mouseover', function () {
        aboutSection.innerHTML = '<h2>关于</h2><p>是要对一个变量来改的，这个变量和HTML中有联系吗？</p>';
    });

    aboutSection.addEventListener('mouseout', function () {
        aboutSection.innerHTML = '<h2>关于</h2><p>这是关于页面的内容。</p>';
    });

    // 动态更改联系部分的背景颜色
    contactSection.addEventListener('click', function () {
        const colors = ['#ffcccc', '#ccffcc', '#ccccff'];
        const randomColor = colors[Math.floor(Math.random() * colors.length)];
        contactSection.style.backgroundColor = randomColor;
    });
});

function square ({value}){
    return <button className = "square">{value} </button>
}


export default function Board (){
    return (
       <>
      <div className="board-row">
        <Square value="1" />
        <Square value="2" />
        <Square value="3" />
      </div>
      <div className="board-row">
        <Square value="4" />
        <Square value="5" />
        <Square value="6" />
      </div>
      <div className="board-row">
        <Square value="7" />
        <Square value="8" />
        <Square value="9" />
      </div>
    </>
    );
}


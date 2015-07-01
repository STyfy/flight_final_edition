#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include<stdlib.h>
char scorestr[10]="0";
int i,p=1,bullet_frequent=1,j,d=1,d2=1,score=0,feplaneshot=1,o=1,k=1,youlive=3,g=1,fuckpower,score2=0,tiaoshi2=0;
int tforplane=1,destroyx,destroyy,destroy=0,destroyxadd,destroyyadd,destroyadd=0,destroyyoux,destroyyouy,destroyyou=0;
float enemy_x[51]={0},enemy_y[51]={0};
int enemy_exist[51]={0},enemy_life[51]={0},enemy_number=1;
float bullet_x[105]={0}, bullet_y[105]={0},bullet_limit[105]={0};
int bullet_is[105]={0};
float enemy_bullet_x[501]={0},enemy_bullet_y[501]={0},enemy_bullet_length[501]={0};
int enemy_bullet_is[501]={0};


float x,y;

void  bullet_f_control()
{
    bullet_frequent++;
        if (bullet_frequent>=200/fuckpower)
            {
                p++;
                if (bullet_is[p]==0)
                    {
                        bullet_is[p]=1;
                        bullet_x[p]=x+48;
                        bullet_y[p]=y;
                        bullet_limit[p]=0;
                    }
                if (p>=96)
                    p=1;
            }
    if (bullet_frequent>=200/fuckpower)
        bullet_frequent=1;
}


int enemy_occur_often(int m)
{
    int fx,n;
    int a=2;
    n=m/2;
    if (n>=0&&n<500)     return 5000/a;
    if (n>=500&&n<1000)  return 4500/a;
    if (n>=1000&&n<1500) return 4000/a;
    if (n>=1500&&n<2000) return 3500/a;
    if (n>=2000&&n<2500) return 3000/a;
    if (n>=2500&&n<3000) return 2500/a;
    if (n>=3000&&n<3500) return 2000/a;
    if (n>=3500&&n<4000) return 1500/a;
    if (n>=4000)         return 1000/a;

}
int main()
{


    sf::RenderWindow window(sf::VideoMode(480,800), "SFML works!");

    sf::Texture sky_texture;
    if (!sky_texture.loadFromFile("background.png",sf::IntRect(0,0,480,800)))
        return EXIT_FAILURE;
    sf::Sprite sky(sky_texture);

    sf::Texture player_texture;
    if (!player_texture.loadFromFile("shoot.png",sf::IntRect(0,100,103,133)))
        return EXIT_FAILURE;
    sf::Sprite player_sprite(player_texture);
    player_sprite.setPosition(sf::Vector2f(200, 600));
    x=200;
    y=600;

    sf::Texture forpowerup;
    if (!forpowerup.loadFromFile("shoot.png",sf::IntRect(266,398,62,88)))
        return EXIT_FAILURE;
    sf::Sprite powerup(forpowerup);

    sf::Texture enemy_texture;
    if (!enemy_texture.loadFromFile("shoot.png",sf::IntRect(0,0,68,100)))
        return EXIT_FAILURE;
    sf::Sprite enemy_sprite(enemy_texture);

    sf::Texture destroy1;
    if (!destroy1.loadFromFile("shoot.png",sf::IntRect(532,650,68,100)))
        return EXIT_FAILURE;
    sf::Sprite spdestroy1(destroy1);

    sf::Texture destroy2;
    if (!destroy2.loadFromFile("shoot.png",sf::IntRect(605,650,68,100)))
        return EXIT_FAILURE;
    sf::Sprite spdestroy2(destroy2);

    sf::Texture destroy3;
    if (!destroy3.loadFromFile("shoot.png",sf::IntRect(670,650,68,100)))
        return EXIT_FAILURE;
    sf::Sprite spdestroy3(destroy3);

    sf::Texture destroy4;
    if (!destroy4.loadFromFile("shoot.png",sf::IntRect(740,650,68,100)))
        return EXIT_FAILURE;
    sf::Sprite spdestroy4(destroy4);

    sf::Texture you1;
    if (!you1.loadFromFile("shoot.png",sf::IntRect(166,236,103,120)))
        return EXIT_FAILURE;
    sf::Sprite dyou1(you1);

    sf::Texture you2;
    if (!you2.loadFromFile("shoot.png",sf::IntRect(330,626,103,120)))
        return EXIT_FAILURE;
    sf::Sprite dyou2(you2);

    sf::Texture you3;
    if (!you3.loadFromFile("shoot.png",sf::IntRect(330,500,103,120)))
        return EXIT_FAILURE;
    sf::Sprite dyou3(you3);


    sf::SoundBuffer bgm;
    if (!bgm.loadFromFile("game_music.ogg"))
        return -1;
    sf::Sound bgm1;
    bgm1.setBuffer(bgm);
    bgm1.play();

    sf::SoundBuffer enemydown;
    if (!enemydown.loadFromFile("enemy1_down.ogg"))
        return -1;
    sf::Sound enemydown1;
    enemydown1.setBuffer(enemydown);

    sf::SoundBuffer _player_down;
    if (!_player_down.loadFromFile("youdown.ogg"))
        return -1;
    sf::Sound player_down;
    player_down.setBuffer(_player_down);

    sf::Texture player_bullet_texture;
    if (!player_bullet_texture.loadFromFile("shoot.png",sf::IntRect(69,78,10,22)))
        return -1;
    sf::Sprite player_bullet_sprite(player_bullet_texture);

    sf::Texture enemy_bullet_texture;
    if (!enemy_bullet_texture.loadFromFile("shoot.png",sf::IntRect(1002,990,10,22)))
        return -1;
    sf::Sprite enemy_bullet_sprite(enemy_bullet_texture);

    //加载字体文件
    sf::Font font;
    if (!font.loadFromFile("score.ttf"))
    return -1;

    sf::Text showscore;
    showscore.setFont(font);
    showscore.setString(scorestr);
    showscore.setCharacterSize(40);
    showscore.setColor(sf::Color::White);

    sf::Text text;
    text.setFont(font);
    text.setString("Score");
    text.setCharacterSize(40);
    text.setColor(sf::Color::White);

    sf::Text die;
    die.setFont(font);
    die.setCharacterSize(22);
    die.setString("You life:2/3,press Tab to continue");
    die.setColor(sf::Color::White);

    sf::Text gg;
    gg.setFont(font);
    gg.setCharacterSize(40);
    gg.setString("GAME  OVER");
    gg.setColor(sf::Color::Red);





    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.draw(sky);
        if (youlive>0)
        {
        if (destroyyou==0)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&x<380)
            {
                player_sprite.move(.5,0);
                x+=0.5;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&x>0)
            {
                player_sprite.move(-.5,0);
                x-=0.5;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&y>0)
            {
                player_sprite.move(0,-.5);
                y-=0.5;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&y<660)
            {
                player_sprite.move(0,.5);
                y+=0.5;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                bullet_f_control();

            }

                window.draw(player_sprite);
        }
        for (i=1;i<=100;i++)
                {
                    if (bullet_is[i]==1)
                    {
                            bullet_y[i]-=0.7;
                            bullet_x[i]+=bullet_limit[i]*0.3;
                            if (bullet_y[i]<0) bullet_is[i]=0;
                            else
                                {
                                    player_bullet_sprite.setPosition(bullet_x[i],bullet_y[i]);
                                    window.draw(player_bullet_sprite);
                                }
                    }
                }

        feplaneshot++;
        if (feplaneshot==enemy_occur_often(score))
        {
            if (enemy_bullet_is[o]==0)
                                {
                                    for (i=1;i<=100;i++)
                                    {
                                        if (enemy_exist[i]==1)
                                        {
                                            k++;
                                            if (k==3)
                                            {
                                            enemy_bullet_is[o]=1;
                                            enemy_bullet_x[o]=enemy_x[i]+32;
                                            enemy_bullet_y[o]=enemy_y[i]+100;
                                            enemy_bullet_length[o]=0;
                                            o++;
                                            k=1;
                                            }
                                        }
                                    }

                                }
            if (o>=500) o=1;
            feplaneshot=1;
        }
        for (i=1;i<=500;i++)
                {
                    if (enemy_bullet_is[i]==1)
                    {
                            enemy_bullet_y[i]+=0.4;
                            enemy_bullet_x[i]+=enemy_bullet_length[i]*0.5;
                            if (enemy_bullet_y[i]>800)
                                enemy_bullet_is[i]=0;
                            else
                                {
                                    enemy_bullet_sprite.setPosition(enemy_bullet_x[i],enemy_bullet_y[i]);
                                    window.draw(enemy_bullet_sprite);

                                }
                    }
                }

        tforplane++;
        if (tforplane==enemy_occur_often(score))
         {
            enemy_number++;
            if (enemy_exist[enemy_number]==0)
             {
                enemy_exist[enemy_number]=1;
                enemy_y[enemy_number]=0;
                enemy_x[enemy_number]=rand()%380;
                enemy_life[enemy_number]=1+score/100;
             }
            if (enemy_number==50) enemy_number=1;
                tforplane=1;
         }
        for (j=1;j<=50;j++)
        {
            if (enemy_exist[j]==1)
            {
               enemy_y[j]+=0.2;
               if (enemy_y[j]>800)
               enemy_exist[j]=0;
               else
               {
                  enemy_sprite.setPosition(enemy_x[j],enemy_y[j]);
                  window.draw(enemy_sprite);
               }
            }
        }
        for (i=1;i<=50;i++)
            for (j=1;j<=100;j++)
            {
                if (enemy_exist[i]==1&&bullet_is[j]==1&&enemy_y[i]<bullet_y[j]&&bullet_y[j]<enemy_y[i]+100&&enemy_x[i]<bullet_x[j]&&bullet_x[j]<enemy_x[i]+68)
                {
                    enemy_life[i]--;
                    bullet_is[j]=0;
                    if (enemy_life[i]==0)
                        {
                             enemy_exist[i]=0;
                             score+=10;
                             sprintf(scorestr,"%d",score+score2);
                             showscore.setString(scorestr);

                             if (destroy==0)
                             {
                             destroyx=enemy_x[i];
                             destroyy=enemy_y[i];
                             destroy=1;
                             }
                             else
                             {
                                 destroyxadd=enemy_x[i];
                                 destroyyadd=enemy_y[i];
                                 destroyadd=1;
                             }
                        }
                }
            }
        for (i=1;i<=50;i++)
        {
            if (enemy_exist[i]==1&&enemy_x[i]+18>x&&x+53>enemy_x[i]&&enemy_y[i]+70>y&&y+103>enemy_y[i]&&destroyyou==0)
            {
                youlive--;
                enemy_exist[i]=0;
                if (destroy==0)
                {
                    destroyx=enemy_x[i];
                    destroyy=enemy_y[i];
                    destroy=1;
                }
                else
                {
                    destroyxadd=enemy_x[i];
                    destroyyadd=enemy_y[i];
                    destroyadd=1;
                }
                destroyyou=1;
                destroyyoux=x;
                destroyyouy=y;

            }
        }
         for (i=1;i<=500;i++)
        {
            if (enemy_bullet_is[i]==1&&enemy_bullet_x[i]>x+31&&enemy_bullet_x[i]<x+71&&enemy_bullet_y[i]>y+37&&enemy_bullet_y[i]<y+97&&destroyyou==0)
            {
                youlive--;
                enemy_bullet_is[i]=0;
                destroyyou=1;
                destroyyoux=x;
                destroyyouy=y;

            }
        }
        if (destroyyou==1)
        {
            g++;
            if (g<=200)
                {
                    dyou1.setPosition(destroyyoux,destroyyouy);
                    window.draw(dyou1);
                    player_down.play();
                }
            if (g>200&&g<=400)
                {
                    dyou2.setPosition(destroyyoux,destroyyouy);
                    window.draw(dyou2);
                }
            if (g>400&&g<600)
                {
                    dyou3.setPosition(destroyyoux,destroyyouy);
                    window.draw(dyou3);
                }
            if (g>600)
            {
            die.setPosition(15,380);
            window.draw(die);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
            {
            player_sprite.setPosition(sf::Vector2f(200, 600));x=200;y=600;
            fuckpower=1;
            destroyyou=0;
            g=1;
            }
            }
        }
        if (destroy==1)
        {
        d++;
        if (d<=200)
            {
                spdestroy1.setPosition(destroyx,destroyy);
                window.draw(spdestroy1);
                enemydown1.play();
            }
        if (d>200&&d<=400)
            {
                spdestroy2.setPosition(destroyx,destroyy);window.draw(spdestroy2);}
        if (d>400&&d<600) {spdestroy3.setPosition(destroyx,destroyy);window.draw(spdestroy3);}
        if (d>=600&&d<800) {spdestroy4.setPosition(destroyx,destroyy);window.draw(spdestroy4);}
        if (d==800) {d=1;destroy=0;}
        }
         if (destroyadd==1)
        {
           d2++;
           if (d2<=200)
            {
                spdestroy1.setPosition(destroyxadd,destroyyadd);
                window.draw(spdestroy1);
                enemydown1.play();
            }
           if (d2>200&&d2<=400)
           {
                spdestroy2.setPosition(destroyxadd,destroyyadd);
                window.draw(spdestroy2);
           }
           if (d2>400&&d2<600)
           {
               spdestroy3.setPosition(destroyxadd,destroyyadd);
               window.draw(spdestroy3);
           }
           if (d2>=600&&d2<800)
            {
                spdestroy4.setPosition(destroyxadd,destroyyadd);
                window.draw(spdestroy4);
           }
        if (d2==800)
            {
                d2=1;
                destroyadd=0;
            }
       }
         text.setPosition(20,20);
         showscore.setPosition(50,60);
         window.draw(text);
         window.draw(showscore);
      }
        else
            {
                gg.setPosition(145,320);
                window.draw(gg);
            }
    window.display();
    }
    return 0;
}

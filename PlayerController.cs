using System;
using System.Collections;
using System.Collections.Generic;
//using System.Diagnostics;
using UnityEngine;
//using UnityEngine.Windows;
using static Unity.IO.LowLevel.Unsafe.AsyncReadManagerMetrics;

public class PlayerController : MonoBehaviour
{
    public Vector3 move;
    public float sensitivity = 400.0f;

    // Для вращения по осям  Speed и Step
    public float RoSpeedX, RoSpeedY, RoSpeedZ = 0f;
    public float RoStepX, RoStepY, RoStepZ = 0f;

    // Для движения по осям  Speed и Step
    public float MoSpeedX, MoSpeedY, MoSpeedZ = 0f;
    public float MoStepX, MoStepY, MoStepZ = 0f;

    // Если в update eсnь transform то пишем через это
  //  public Transform Transform => GetComponent<Transform>();

    private void Update()
    {
        // Пауза
        if (Input.GetKeyDown(KeyCode.P)) Time.timeScale = Time.timeScale == 0 ? 1f : 0f;

        // Tормоз
        if (Input.GetKeyDown(KeyCode.BackQuote) || Input.GetKeyDown(KeyCode.Alpha0))
            {
                move = new Vector3(0f, 0f, 0f);

            RoSpeedX = RoSpeedY = RoSpeedZ = 0f;
            RoStepX = RoStepY = RoStepZ = 0f;
            MoSpeedX = MoSpeedY = MoSpeedZ = 0f;
            MoStepX = MoStepY = MoStepZ = 0f;
        }



        // Выход из приложения через правый шифт и q
        if (Input.GetKey(KeyCode.RightShift))
            if (Input.GetKeyDown(KeyCode.Q)) { Debug.Log("Q"); Application.Quit(); }


        if (Input.GetKey(KeyCode.LeftShift))     //  || Input.GetKey(KeyCode.RightShift)
        {
            if (Input.GetKeyDown(KeyCode.Alpha1)) RoStepX = RoStepY = RoStepZ = 0f;
            if (Input.GetKeyDown(KeyCode.Alpha2)) RoStepX = RoStepY = RoStepZ = 2f;
            if (Input.GetKeyDown(KeyCode.Alpha3)) RoStepX = RoStepY = RoStepZ = 4f;
            if (Input.GetKeyDown(KeyCode.Alpha4)) RoStepX = RoStepY = RoStepZ = 10f;

            // Перевороты  расчет   
            if (Input.GetKeyDown(KeyCode.A)) RoSpeedX += RoStepX; // RoStepX;
            if (Input.GetKeyDown(KeyCode.D)) RoSpeedX -= RoStepX; //RoStepX;

            if (Input.GetKeyDown(KeyCode.E)) RoSpeedY += RoStepY * 2; //RoStepY;
            if (Input.GetKeyDown(KeyCode.Q)) RoSpeedY -= RoStepY * 2; //RoStepY;

            if (Input.GetKeyDown(KeyCode.W)) RoSpeedZ += RoStepZ; //RoStepZ;
            if (Input.GetKeyDown(KeyCode.S)) RoSpeedZ -= RoStepZ; //RoStepZ;
        }
        else
        {
            // выбор скорости
            if (Input.GetKeyDown(KeyCode.Alpha1)) MoStepX = MoStepY = MoStepZ = 0f;
            if (Input.GetKeyDown(KeyCode.Alpha2)) MoStepX = MoStepY = MoStepZ = 1f;
            if (Input.GetKeyDown(KeyCode.Alpha3)) MoStepX = MoStepY = MoStepZ = 10f;
            if (Input.GetKeyDown(KeyCode.Alpha4)) MoStepX = MoStepY = MoStepZ = 100f;
            if (Input.GetKeyDown(KeyCode.Alpha5)) MoStepX = MoStepY = MoStepZ = 1000f;

            // рaсчет для Vectora3
            if (Input.GetKeyDown(KeyCode.D)) MoSpeedX += MoStepX;
            if (Input.GetKeyDown(KeyCode.A)) MoSpeedX -= MoStepX;

            if (Input.GetKeyDown(KeyCode.E)) MoSpeedY += MoStepY;
            if (Input.GetKeyDown(KeyCode.Q)) MoSpeedY -= MoStepY;

            if (Input.GetKeyDown(KeyCode.W)) MoSpeedZ += MoStepZ;
            if (Input.GetKeyDown(KeyCode.S)) MoSpeedZ -= MoStepZ;

            if (Input.GetKeyDown(KeyCode.PageUp))   { MoSpeedX *= 2f; MoSpeedY *= 2f; MoSpeedZ *= 2f; }
            if (Input.GetKeyDown(KeyCode.PageDown)) { MoSpeedX /= 2f; MoSpeedY /= 2f; MoSpeedZ /= 2f; }

            move = new Vector3(MoSpeedX, MoSpeedY, MoSpeedZ);
        }



        // Действие корпуса WSDA
        if (move != new Vector3(0, 0, 0)) transform.Translate(move * Time.deltaTime);
        // Поворот корпуса в лево право по Y
        if (RoSpeedY != 0) transform.Rotate(new Vector3(0f, RoSpeedY, 0) * Time.deltaTime, Space.Self);

        // Старый вариант движения корабля
        // move = new Vector3(Input.GetAxis("Horizontal"), 0, Input.GetAxis("Vertical")).normalized;


                                                //     Debug.Log(move + "/          speed/" + speed + "/        RoSpeedXYZ/" + RoSpeedX + "/" + RoSpeedY + "/" + RoSpeedZ + "/              RoSpeedXYZ/ " + RoSpeedX + "/" + RoSpeedY + "/" + RoSpeedZ + "/");
                                                // if(Input.anyKey || Input.anyKeyDown) Debug.Log($"{MoStepX}/{MoSpeedX}/{MoSpeedY}/{MoSpeedZ}          {RoStepX}/{RoSpeedX}/{RoSpeedY}/{RoSpeedZ}");
                                                
        // Перевороты  по Z
        if (RoSpeedX != 0f) 
            transform.Rotate(new Vector3(0f, 0f, RoSpeedX) * Time.deltaTime, Space.Self);
        if (RoSpeedZ != 0f) 
            transform.Rotate(new Vector3(RoSpeedZ, 0f, 0f) * Time.deltaTime, Space.Self);

       // МЫШЬ Camera.main.
       Camera.main.transform.Rotate(
           Input.GetAxis("Mouse Y") * sensitivity * Time.deltaTime,
           Input.GetAxis("Mouse X") * sensitivity * Time.deltaTime,
           0,
           Space.Self);


        if (Input.GetKeyDown(KeyCode.Space))
            Camera.main.transform.rotation = Quaternion.Slerp(transform.rotation, Quaternion.Euler(0,0,0), 0.01f * Time.deltaTime);

        //Camera.main.transform.Rotate(
        //    Mathf.Clamp(Input.GetAxis("Mouse Y"), -1f, 1f) * sensitivity * Time.deltaTime,  //0,
        //    Input.GetAxis("Mouse X") * sensitivity * Time.deltaTime,
        //    0);


    }
}








//  if (Input.GetKey(KeyCode.LeftShift) || Input.GetKey(KeyCode.RightShift))

/*
using UnityEngine;
using System.Collections;

public class CameraController : MonoBehaviour {
//Переменные ***************************************************
  public float horizontalSpeed = 2.0F;
     public float verticalSpeed = 2.0F;
  public float speed = 1f;  
  private Transform myTransform;
//**************************************************************
   
  void Start(){
   myTransform = transform; // оптимизация
   Screen.showCursor = false; //убрать курсор
  }
   
     void Update() {     
         float h = horizontalSpeed * Input.GetAxis("Mouse X");
         float v = verticalSpeed * Input.GetAxis("Mouse Y");
    
         myTransform.Rotate(v, h, 0);

   }
     }

------------------------------------------------------------------
а вот самого корабля
------------------------------------------------------------------

using UnityEngine;
using System.Collections;

public class ShipController : MonoBehaviour {
  //пременные***************************************
  public Transform target;//цель
  public int moveSpeed; //скорость перемещения
  public int rotationSpeed; //скорость поворота
  public float rot = 1.0f;
   
  private Transform myTransform ;//временная переменная для хранения ссылки
                    //на свойство transform (это оптимизация)
  //************************************************
  void Awake (){
        //ссылаемся на свойство transform для того чтобы сократить время
        //обращения к нему в скрипте
        myTransform = transform;
  }

  // начальная инициализация
  void Start () {
        //ищем обьект по тегу Player
        GameObject go = GameObject.FindGameObjectWithTag("aim");
        //и делаем его целью
        target = go.transform;    
  }
   
  // Update is called once per frame
  void Update () {
   //чертим вспомогательную линию от нас к игроку
   Debug.DrawLine(target.position, myTransform.position,
                      Color.yellow);
   //поворачивемся в сторону игрока
   myTransform.rotation = Quaternion.Slerp(myTransform.rotation,
                       Quaternion.LookRotation(target.position - myTransform.position),
                       rotationSpeed * Time.deltaTime);
   //усли позволяет дистанция двигаемся к игроку
   if(moveSpeed >0){
   //двигаемся к цели
   myTransform.position += myTransform.forward * moveSpeed * Time.deltaTime;  
    
   rot = -5*Input.GetAxis("Mouse X");
   myTransform.Rotate(0,0,rot);
   }
  }
}
*/
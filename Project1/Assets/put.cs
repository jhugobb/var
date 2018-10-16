using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;

public class put : MonoBehaviour
{

    public Rigidbody objMovible;


    public void drop()
    {
        objMovible.isKinematic = false;
        objMovible.detectCollisions = true;
        objMovible.transform.parent = gameObject.transform;
        objMovible.transform.rotation = new Quaternion(0f, 0f, 0f, 0f);
        objMovible.transform.position = new Vector3(gameObject.transform.position.x, gameObject.transform.position.y + 1, gameObject.transform.position.z);
        GetComponent<Renderer>().material.color = objMovible.GetComponent<Renderer>().material.color;
        GetComponent<EventTrigger>().enabled = false;


    }
}
